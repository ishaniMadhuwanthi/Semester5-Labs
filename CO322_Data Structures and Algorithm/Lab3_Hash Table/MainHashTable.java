/********************************************
 * CO322: Data structures and algorithms
 * Interface for the HashTable
 ********************************************
 */
/*
E/15/211
CO322-Lab03
*/

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class MainHashTable extends HashTableImp
{	
	public MainHashTable(int buckets) 
	{
		super(buckets);		
	} 

	public static void main(String[]args)
	{				
		String line="";
		int hashTableSize=0;//initail value for the hashtable size		
		MainHashTable hashMap = null;
		
		//Extracting number of buckets from command line
		if(args[0].equals("-b"))//in therminal user should compile like this-->Java MainHashTable -b [#buckets] -i [filename]
		{
			hashTableSize = Integer.valueOf(args[1]);
			hashMap = new MainHashTable(hashTableSize);//create new hashmap
			
			if(args[2].equals("-i"))
			{
				//Read the Text Files
				String fileName = args[3];
				try(BufferedReader br = new BufferedReader(new FileReader(fileName)))
				{
					while((line = br.readLine())!=null)
					{
						//Converting all non-alphanumberic characters to whitespace 					
						String text = line.replaceAll("\\W"," ");
						String tokens[] = text.split("\\s+");//split lines between whitespaces
						for(String s:tokens)
						{
							hashMap.insert(s);//insert strings to hash table 		 		
						}
					}			
				}		
				catch (FileNotFoundException e)
				{
					System.out.println("File does not exists");
					System.exit(0);
				}
				catch (IOException e) 
				{
					System.out.println("File reading failed");
					System.exit(0);
				}		
				//Print overall information of contents and it's distribution in the hash table 
				hashMap.getBucketSize(hashTableSize);
				System.out.println();
				
				try(Scanner ip = new Scanner(System.in))
				{				
					String key;
					do 
					{
						//user can enter a key to search from the hash table
						System.out.println("Enter a key to search: ");
						key = ip.nextLine();
						System.out.println("Value: "+hashMap.search(key));
					}
					while(!key.equals("q"));
				}				
			}
			else
			{
				cmdInst();
			}
		}		
		else
		{
			cmdInst();
		}
	}
	
	//command line instructions for the user
	private static void cmdInst()
	{
		System.out.println("You should compile the program like this,Insert-> Java MainHashTable -b [#buckets] -i [filename]");	
		System.out.println("To quit from loop-> q");
	}
}

    
