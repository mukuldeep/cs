class Ec_crypto{
			
			constructor(){
				this.P =BigInt(115792089237316195423570985008687907853269984665640564039457584007908834671663);//  # prime number for modulus operations
				this.order = BigInt(0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141);//   # order for the elliptic curve y^2=x^3+7 ,used in bitcoin
				this.Gx = BigInt(55066263022277343669578718895168534326250603453777594175500187360389116729240);//   # x co-ordinate of generating point of secp256k1 i.e. curve used in bitcoin
				this.Gy = BigInt(32670510020758816978083085130507043184471273380659243275938904335757337482424);//   # y co-ordinate of generating point of secp256k1 i.e. curve used in bitcoin
			}
			
			//# mod inverse
			//# Extended Euclidean Algorithm for finding mod inverse
			modinv(a, n){
				let lm=BigInt(1);
				let hm=BigInt(0);
				let low=BigInt(a%n);
				let high=BigInt(n);
				while(low > BigInt(1)){
					let ratio = high/low;
					let nm = hm - lm * ratio;
					let new_ = high - low * ratio;
					hm = lm;
					high = low;
					lm = nm;
					low = new_;
				}
				return (n+lm) % n;
			}
			
			//# Elliptic curve point addition
			ECadd(xp, yp, xq, yq){
				//# point addition will not work if both the point are same. So, point doubling is required
				if(xp == xq && yp == yq)
					return this.ECdouble(xp, yp);

				let m = ((yq - yp) * this.modinv(xq - xp, this.P)) % this.P;
					if(m<BigInt(0))m=m+this.P;
				let xr = (m * m - xp - xq) % this.P;
					if(xr<BigInt(0))xr=xr+this.P;
				let yr = (m * (xp - xr) - yp) % this.P;
					if(yr<BigInt(0))yr=yr+this.P;
				
				if(xr<BigInt(0))xr=xr+this.order;
				if(yr<BigInt(0))yr=yr+this.order;
				return [xr, yr];
			}
			
			//# Elliptic curve point doubling
			ECdouble(xp, yp){
				let l = ((BigInt(3) * xp * xp) * this.modinv(BigInt(2) * yp, this.P)) % this.P;
					if(l<BigInt(0))l=l+this.P;
				let X = (l * l - BigInt(2) * xp) % this.P;
					if(X<BigInt(0))X=X+this.P;
				let Y = (l * (xp - X) - yp) % this.P;
					if(Y<BigInt(0))Y=Y+this.P;
				
				if(X<BigInt(0))X=X+this.order;
				if(Y<BigInt(0))Y=Y+this.order;
				return [X,Y];
			}
			
			//# Elliptic curve point multiplication
			//##1. scaler multiplication with generator point
			ECmult(scaler){
				if(scaler == BigInt(0))
					return [BigInt(0), BigInt(0)];
				
				let _2pX=this.Gx;
				let _2pY=this.Gy;
				let _X = this.Gx;
				let _Y = this.Gy;
				scaler=scaler-BigInt(1);
				
				while(scaler){
					var ecdb= this.ECdouble(_2pX, _2pY);
					_2pX=ecdb[0];
					_2pY=ecdb[1];
					if(scaler%BigInt(2)==BigInt(1)){
						var ecad= this.ECadd(_2pX,_2pX,_X,_Y);
						// console.log(scaler);
						// console.log(ecad);
						_X=ecad[0];
						_Y=ecad[1];
						if(_X<BigInt(0))_X=_X+this.order;
						if(_Y<BigInt(0))_Y=_Y+this.order;
					}
					scaler=scaler/BigInt(2);
				}
				
				if(_X<BigInt(0))_X=_X+this.order;
				if(_Y<BigInt(0))_Y=_Y+this.order;
				return [_X, _Y];
			}
			
			// ##2. scaler multiplication with other point on secp256k1 curve
			// ###Example 2*(4G)=8G 4*(5G)=20G etc.
			ECmultp(Sx, Sy, scaler){
				if(scaler == BigInt(0))
					return [BigInt(0), BigInt(0)];
				
				let _2pX=Sx;
				let _2pY=Sy;
				let _X = Sx;
				let _Y = Sy;
				scaler=scaler-BigInt(1);
				
				while(scaler){
					var ecdb= this.ECdouble(_2pX, _2pY);
					_2pX=ecdb[0];
					_2pY=ecdb[1];
					if(scaler%BigInt(2)==BigInt(1)){
						var ecad= this.ECadd(_2pX,_2pX,_X,_Y);
						_X=ecad[0];
						_Y=ecad[1];
					}
					scaler=scaler/BigInt(2);
				}
				if(_X<BigInt(0))_X=_X+this.order;
				if(_Y<BigInt(0))_Y=_Y+this.order;
				
				return [_X, _Y];
			}
			
			getRandomInt() {
			  let min = 100;
			  let max = 100000000000000000;
			  return ""+Math.floor(Math.random()*(max - min) + min)+""+Math.floor(Math.random()*(max - min) + min)+""+Math.floor(Math.random()*(max - min) + min);
			}
			
			//#Generate a private key
			generate_private_key(){
				let rn = BigInt(this.getRandomInt());
				return rn;
			}
			
			//#private key to public key conversion i.e. x coordinate of G*priv
			private_to_public(priv_k){
				return this.ECmult(priv_k)[0];
			}

		}	