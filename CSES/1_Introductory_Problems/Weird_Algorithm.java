import java.util.Scanner;
 
public class Weird_Algorithm {
 
    public static void main(String[] args) {
        Scanner lec = new Scanner(System.in);
        StringBuilder cad = new StringBuilder();
        long n;
        
        n = lec.nextInt();
        
        while(n!=1){
            cad.append(n);
            cad.append(" ");
            
            if(n%2==0){
                n/=2;
            }
            else{
                n=n*3+1;
            }
        }
        
        cad.append(1);
        System.out.println(cad);
    }
    
}