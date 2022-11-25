#!/usr/bin/python
###############################################################################################
# encrypt a file; decrypt.py puts them                                                        #
# back together                                                                               #
###############################################################################################

import sys, os
import random
import math
def progress_bar(current, total, bar_length=100):
    fraction = current / total
    arrow = int(fraction * bar_length - 1) * '-' + '>'
    padding = int(bar_length - len(arrow)) * ' '
    ending = '\n' #if current == total else '\r'
    print(f'Progress: [{arrow}{padding}] {int(fraction*100)}%', end=ending)

chunksize=1024*1024*10
def get_key():
  return os.urandom(chunksize)
  return random.randrange(1<<250, 1<<255, 1)
def xr(var, key):
    xx= bytes(a ^ b for a, b in zip(var, key))
    return xx
def xr2(var, key, byteorder=sys.byteorder):
    key, var = key[:len(var)], var[:len(key)]
    int_var = int.from_bytes(var, byteorder)
    int_key = int.from_bytes(key, byteorder)
    int_enc = int_var ^ int_key
    return int_enc.to_bytes(len(var), byteorder)

def encrypt(fromfile):
    #chunksize=1024*1024*10
    enc_key=get_key()
    #print(enc_key)
    print("key generated")
    file_size = os.path.getsize(fromfile)
    total_no_chunk=math.floor(file_size/chunksize)
    curr_chunk_no=0                       
    input = open(fromfile, 'rb')
    fileobj  = open( fromfile+".enc", 'wb')               
    while 1:
        curr_chunk_no+=1              
        chunk = input.read(chunksize)
        if not chunk: break
        chunk=xr2(chunk,enc_key)
        fileobj.write(chunk)
        progress_bar(curr_chunk_no,total_no_chunk)        
    input.close(  )
    fileobj.close()

    fileobj2  = open(fromfile+".key", 'wb')
    fileobj2.write(enc_key)
    fileobj2.close()

   
            
if __name__ == '__main__':
    if len(sys.argv) == 2 and sys.argv[1] == '-help':
        print( 'Use: encrypt.py [file-to-encrypt]')
    else:
        if len(sys.argv) < 2:
            interactive = 1
            fromfile = raw_input('File to be encrypt? ')        
        else:
            interactive = 0
            fromfile = sys.argv[1]                 
        print( 'encrypting',fromfile, 'to', fromfile, '.enc and ',fromfile,".key")

        try:
            encrypt(fromfile)
        except:
            print( 'Error during encrypt:')
        else:
            print('encryption finished: ')
        if interactive: raw_input('Press Enter key') # pause if clicked