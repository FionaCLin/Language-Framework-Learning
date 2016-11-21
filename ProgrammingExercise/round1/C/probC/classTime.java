import java.util.Scanner;

public class classTime{
	public static void main(String [] args){
		//String alphabet = "abcdefghijklmnopqrstuvwxyz";
		Scanner kb= new Scanner(System.in);
		int size=kb.nextInt();
		kb.nextLine();
		while(true){
			if(size>100 || size<0){
				System.out.println("Number must be between 0 and 100");
			}else{
				
				break;
			}
		}
		String [] names=new String[size];
		for(int i=0; i < size;i++){
			names[i]=kb.nextLine();
		}
		  
		//sorting
		while(true){
			int sortCount=0;
			for(int i=0;i<names.length-1;i++){
				//check first name;
				int boundary=names[i].length();
				if(names[i].length()>names[i+1].length()){
					boundary=names[i+1].length();
				}
				for(int j=0;j<boundary;j++){
					char c1=names[i].charAt(0);
					char c2=names[i+1].charAt(0);
					System.out.println(c1);
					System.out.println((int)c1);
					System.out.println(c2);
					System.out.println((int)c2);
					if((int)c1>(int)c2){
						String sw=names[i+1];
						names[i+1]=names[i];
						names[i]=sw;
						sortCount++;
						System.out.println(names[i]+" "+names[i+1]);
					}
					else if((int)c1==(int)c2){
						c1=(names[i].split(" "))[1].charAt(0);
						c2=(names[i+1].split(" "))[1].charAt(0);
						if((int)c1>(int)c2){
							String sw=names[i+1];
							names[i+1]=names[i];
							names[i]=sw;
							sortCount++;
						}
						System.out.println(names[i]+" "+names[i+1]);
					}
				}
			}
			System.out.println(sortCount);
			if(sortCount==0){
				break;
			}
		}
		for(String i :names){
			System.out.println(i);
		}
	}
	private static void swap(String s1,String s2){
		String temp = s1;
		s1=s2;
		s2=temp;
	}
}