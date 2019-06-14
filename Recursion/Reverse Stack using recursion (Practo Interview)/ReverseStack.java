package test;

// reverse stack using recursion
// only two operations are allowed - PUSH and POP


import java.util.*;

public class ReverseStack {
	public static void main(String[] args) {
		Stack<Integer> stck=new Stack<Integer>();
		stck.push(1);
		stck.push(2);
		stck.push(3);
		stck.push(4);
		stck.push(5);
		
		System.out.println("Before Reverse");
		System.out.println(stck);
		
		reverse(stck);
		
		System.out.println("\nAfter Reverse");
		System.out.println(stck);
	}
	
	
	static void reverse(Stack<Integer> stck)
	{
		if(stck.size()==0)
			return;
		int tmp=stck.pop();
		reverse(stck);
		bottomPush(stck,tmp);
	}
	
	
	static void bottomPush(Stack<Integer> stck, int tmp)
	{
		if(stck.size()==0)
		{
			stck.push(tmp);
			return;
		}
		
		int x=stck.pop();
		bottomPush(stck,tmp);
		stck.push(x);
	}
	
}
