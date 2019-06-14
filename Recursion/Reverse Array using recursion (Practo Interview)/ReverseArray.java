package test;

public class ReverseArray {

	public static void main(String[] args) {
		int arr[]=new int[] {1,2,3,4,5};
		
		System.out.println("Before Reverse");
		for(int i:arr)
			System.out.print(i+" ");
		
		reverse(arr,0);
		
		System.out.println("\n\nAfter reverse");
		for(int i:arr)
			System.out.print(i+" ");
	}
	
	
	static void reverse(int arr[],int i)
	{
		if(i==arr.length)
			return;
		int tmp=arr[i];
		reverse(arr,i+1);
		arr[arr.length-i-1]=tmp;
	}
	
}
