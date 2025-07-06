x:=File standardInput readLine asNumber
N0 := 0;
N1 := 1;
for(i,1,x,
N2 := N1+N0;
N0 := N1;
N1 := N2;
);
N2 println;