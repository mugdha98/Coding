//First Negative Integer in every Window of size K
//Print 0 when there is no _ve number in the window
package Sliding_Window;

import java.util.Scanner;
import java.util.Vector;

public class First_Negative {
    public static void main(String[] args) {
        Vector<Integer>v=new Vector<>();
        int n,k;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        k=sc.nextInt();
        //Logic
        int i=0,j=0;
        while(j<n){
            if(arr[j]<0)v.add(arr[j]);

            if(j-i+1<k)j++;
            else if(j-i+1==k){
                if(v.isEmpty())System.out.print("0"+" ");
                else System.out.print(v.get(0)+" ");
                if(!v.isEmpty()&& arr[i]==v.get(0))v.remove(0);
                i++;j++;
            }
        }
        sc.close();
    }
}
