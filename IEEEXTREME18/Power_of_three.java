import java.io.*;
import java.math.*;

public class Power_of_three {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger n = new BigInteger(br.readLine());
        
        int res = 0;
        BigInteger tres = BigInteger.valueOf(3);
        BigInteger p = BigInteger.valueOf(1);
        while (p.compareTo(n) == -1) {
            p = p.multiply(tres);
            res++;
            // p = p * tres;
        }

        if (p.compareTo(n) != 0) {
            res = -1;
        }

        System.out.println(res);
    }
    
}