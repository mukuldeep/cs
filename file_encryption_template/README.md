## Encryption decryption template
 - encrypting file: python encrypt.py file_path_to_be_encrypted
   - .enc and .key file be generated after encryption
 - decrypting file: python decrypt.py file_path_after_decryption
   - .enc and .key files should be present at that same target folder
 - currently encryption and decryption is only bitwise XOR-ing between file chunks and key. you can implement your method of encryption.  
