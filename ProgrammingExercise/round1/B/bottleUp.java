import java.util.Scanner;
public class bottleUp{
	public static void main(String [] args){
		Scanner kb=new Scanner(System.in);
		int s=kb.nextInt();
		int v1=kb.nextInt();
		int v2=kb.nextInt();
		if(v1<v2){
			int temp =v1;
			v1=v2;
			v2=temp;
		}
		int nOfv1=s/v1;
		int min=0;
		for(int i=1;i<nOfv1+1;i++){
			double nOfv2=(s-i*v1)/v2;
			if(nOfv2%1==0){				
				if(nOfv2*v2+i*v1==s){
					if(min>(int)nOfv2+i){
						nOfv1=i;
						System.out.println("no:"+i);
						System.out.println(nOfv2);
					}
				}
				
			}
			
		}
		int nOfv2=min-nOfv1;
		
		System.out.println(min);
		
	}	
}