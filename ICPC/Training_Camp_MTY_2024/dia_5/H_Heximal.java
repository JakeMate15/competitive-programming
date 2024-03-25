import java.io.*;
import java.math.*;

public class H_Heximal {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger n = new BigInteger(br.readLine());
        System.out.println(n.toString(6).length());
    }
}