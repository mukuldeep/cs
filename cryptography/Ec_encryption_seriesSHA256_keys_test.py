#import crypto class first
import crypto
cr=crypto()

#private key
s_pr_k=123873482648723345345346478237468273 #senders private key
r_pr_k=37458347958734957236478237468273 #reveiver private key
r=86878768768768786768768678 #a random number **THIS NUMBER SHOULD BE GENERATED USING SOME GOOD RANDOM FUNCTION

#public key
s_pub_k=cr.ECmult(s_pr_k)#sender's public key
r_pub_k=cr.ECmult(r_pr_k)#receiver's public key

#message to be sent
msg="SHA, $ ( Secure Hash Algorithms ) are set of cryptographic hash functions defined by the language to be used for various applications such as password security etc. Some variants of it are supported by Python in the 'hashlib' library. These can be found using 'algorithms_guaranteed' function of hashlib."
print("message:          ",msg)

#encrypted message 
enc_msg=cr.encrypt_ser_message(msg,r,s_pr_k,r_pub_k)
print("encrypted message:",enc_msg)

#decrypted message
dec_msg=cr.decrypt_ser_message(enc_msg,r,r_pr_k,s_pub_k)
print("decrypted message:",dec_msg)
