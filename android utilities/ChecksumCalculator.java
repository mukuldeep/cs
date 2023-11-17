package your.package.name.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class ChecksumCalculator {
    /*
    //# usage
    File fileToCheck = new File("/path/to/your/file");
    String algorithm = "SHA-256"; // Choose the desired algorithm
    try {
        String checksum = ChecksumCalculator.calculateChecksum(fileToCheck, algorithm);
        // Use the checksum as needed
    } catch (NoSuchAlgorithmException | IOException e) {
        e.printStackTrace();
    }

     */

    public static String calculateChecksum(File file, String algorithm) throws NoSuchAlgorithmException, IOException {
        MessageDigest digest = MessageDigest.getInstance(algorithm);
        FileInputStream inputStream = new FileInputStream(file);
        byte[] buffer = new byte[8192];
        int bytesRead;

        while ((bytesRead = inputStream.read(buffer)) != -1) {
            digest.update(buffer, 0, bytesRead);
        }

        byte[] hashBytes = digest.digest();

        StringBuilder hexStringBuilder = new StringBuilder();
        for (byte hashByte : hashBytes) {
            hexStringBuilder.append(String.format("%02x", hashByte));
        }

        return hexStringBuilder.toString();
    }
}
