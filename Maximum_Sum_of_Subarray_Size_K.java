//Find the Maximum Sum of subarray of size k
package Sliding_Window;

import java.util.Scanner;


public class Maximum_Sum_of_Subarray_Size_K {

    public int max(int[] arr,int k){
        int maxi=Integer.MIN_VALUE;

        int i=0,j=0;
        int sum=0;
        while(j<arr.length){
            sum+=arr[j];
            if(j-i+1 <k)j++;
            else{
                maxi=Math.max(sum, maxi);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
    public static void main(String[] args) {

        //user input
        int n,k;
        Scanner sc= new Scanner(System.in);
        n= sc.nextInt();
        k=sc.nextInt();

        int arr[]=new int[n];

        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        sc.close();
        
        //logic
        Maximum_Sum_of_Subarray_Size_K ans= new Maximum_Sum_of_Subarray_Size_K();
        System.out.println("Maximum subarray:"+ans.max(arr,k));
    }
}
