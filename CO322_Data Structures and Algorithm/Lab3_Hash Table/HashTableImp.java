/********************************************
 * CO322: Data structures and algorithms
 * Interface for the HashTable
 ********************************************
 */
/*
E/15/211
CO322-Lab03
*/


public class HashTableImp implements HashTable
{
   private static class ListNode 
   {
      String key;//define a key fro searching 
      int value=0;
      ListNode next;  //Pointer to next node in the list;
   }

   public ListNode[] table;  //The hash table                            
   private int count;  //The number of (key,value) pairs in the hash table                   
   
   public HashTableImp(int buckets) //buckets-number of buckets
   {
      if(buckets <= 0) throw new IllegalArgumentException("Illegal table size");
      	table = new ListNode[buckets];
   }
   
   public void insert(String key) 
   {   
      assert key != null : "The key must be non-null";
      
      int bucket = hash(key); //Calculating Hash code for the given key and get bucket number
      ListNode list=null;
      try{list = table[bucket]; //For traversing the linked list}
      
      }catch(ArrayIndexOutOfBoundsException e) {
    	  System.out.println(bucket);
      }
                              
      while (list != null) 
      {
         if (list.key.equals(key))//Search the nodes in the list, to see if the key already exists.
            break;
         list = list.next;
      }
      
      
      if (list != null) //At this point, either list is null, or list.key.equals(key)
      {
         //Since list is not null, we have found the key.
         list.value++; //Update the value
      }
      else 
      {
         ListNode newNode = new ListNode();
         newNode.key = key;
         newNode.value++;
         newNode.next = table[bucket];
         table[bucket] = newNode;
         count++;  //Count the newly added key.
      }
   }

   //Retrieve the value associated with the specified key in the table, if there is any. If not, the value null will be returned.
   public int search(String key) 
   {   
      int bucket = hash(key);
      ListNode list = table[bucket];
      while (list != null) 
      {                 
         if (list.key.equals(key))
            return list.value;
         list = list.next;
      }
      //If it get to this point, then it have looked at every node in the list without finding the key.
      //Hence return 0 to indicate that the key does not exists.
      return 0;  
   }
  
   public boolean containsKey(String key) //Test whether the specified key is already in the table.
   {   
      int bucket = hash(key);
      ListNode list = table[bucket];
      
      while (list != null) 
      {
         //If we find the key in this node, return true.
         if (list.key.equals(key))
            return true;
         list = list.next;
      }
      
      //If we get to this point, we know that the key does not exists.
      return false;
   }
   

   public int getSize() //Return the number of key/value pairs in the table.
   {
      return count;
   }

   //Compute a hash code for the key; key cannot be null.
   //The hash code depends on the size of the table.
   private int hash(String key) 
   {
	   int h = 0;
	   for (int i = 0; i < key.length(); i++)
	   {
		   h = (541*h + key.charAt(i))%table.length;	//multiplied with 31,37,...an odd number	   
	   }	 
	   return (h%table.length);   
   }
   

   public void getBucketSize(int length)  //Returns the number of nodes in the specified bucket
   {
	   int x2=0;
	   int sum = 0;
	   for(int i=0;i<length;i++)
	   { 		
		   int counter=0;
		   ListNode list = table[i];
		   while(list != null)
		   {		 
			   list = list.next;
			   counter++;
		   }
		   sum+=counter;
		   x2=x2+(int) Math.pow(counter,2);
		   System.out.println((i+1)+":"+counter);
	   }	   
	   float avg = (float)(sum/(float)length);
	   float var = (float)(x2/length) - (float)(Math.pow(avg, 2));
                   //print Total,Average and deviation of the table
	   System.out.println("Total:"+sum);
	   System.out.println("Avg:"+avg);
	   System.out.println("Deviation:"+Math.sqrt(var));
  
 }
}

   

