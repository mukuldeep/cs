#!/usr/bin/python
#############################################################################################
# encrypt a file; decrypt.py puts them                                                      #
# back together                                                                             #
#############################################################################################

import sys, os
import random
import math

#encryption key size in bytes (currently 10M) 
chunksize=10*1024*1024

#progress bar
def progress_bar(current, total, bar_length=100):
    fraction = current / total
    arrow = int(fraction * bar_length - 1) * '-' + '>'
    padding = int(bar_length - len(arrow)) * ' '
    ending = '\n' if current == total else '\r'
    print(f'Progress: [{arrow}{padding}] {int(fraction*100)}%', end=ending)

#random key generator
def get_key():
  return os.urandom(chunksize)
  return random.randrange(1<<250, 1<<255, 1)

# function 1. for encryption 
# xor function 1 
def xr(var, key):
    xx= bytes(a ^ b for a, b in zip(var, key))
    return xx
# function 2. for encryption 
# xor function 2 (faster than xr i.e. function 1)
def xr2(var, key, byteorder=sys.byteorder):
    key, var = key[:len(var)], var[:len(key)]
    int_var = int.from_bytes(var, byteorder)
    int_key = int.from_bytes(key, byteorder)
    int_enc = int_var ^ int_key
    return int_enc.to_bytes(len(var), byteorder)

# decryption 
def decrypt(tofile):
    #chunksize=256
    #factor=10
    
    fileobj2  = open(tofile+".key", 'rb')
    enc_key=fileobj2.read()
    fileobj2.close()
    #print(enc_key) 
    #fac_enc_key=

    file_size = os.path.getsize(tofile+".enc")
    print(file_size)
    vvv=file_size/chunksize
    print(vvv)
    total_no_chunk=math.floor(vvv)
    print(total_no_chunk)
    curr_chunk_no=0    

    input = open(tofile+".enc", 'rb')
    print(tofile+".enc file opened for read")
    fileobj  = open( tofile, 'wb')
    print(tofile+" file opened for write")

    while 1:
        curr_chunk_no+=1              
        chunk = input.read(chunksize)
        if not chunk: break
        chunk=xr2(chunk,enc_key)
        fileobj.write(chunk)   
        progress_bar(curr_chunk_no,total_no_chunk)      
    input.close()
    fileobj.close()

   
            
if __name__ == '__main__':
    if len(sys.argv) == 2 and sys.argv[1] == '-help':
        print( 'Use: decrypt.py [file-after-decrypt]')
    else:
        if len(sys.argv) < 2:
            interactive = 1
            tofile = raw_input('File to be decrypted(after decryption, enc and key file path without extenion)? ')        
        else:
            interactive = 0
            tofile = sys.argv[1]                 
        print( 'decrypting to ',tofile, 'from', tofile,'.enc and ',tofile,".key")

        try:
            decrypt(tofile)
        except:
            print( 'Error during encrypt:')
        else:
            print('decryption finished: ')
        if interactive: raw_input('Press Enter key') # pause if clicked