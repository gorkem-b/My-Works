
public class QueueArray {
	/* Member variable declaration */  
	  private int maxSize;  
	  private int[] queueArray;  
	  private int front;  
	  private int rear;  
	  private int currentSize;  
	  /* Constructor */  
	  public QueueArray(int size)  
	  {  
	    this.maxSize = size;  
	    this.queueArray = new int[size];  
	    front = 0;  
	    rear = -1;  
	    currentSize = 0;  
	  }  
	  /* Queue:Insert Operation */  
	  public void enqueue(int item)  
	  {  
	    /* Checks whether the queue is full or not */  
	    if(isQueueFull())  
	    {  
	      System.out.println("Queue is full!");  
	      return;  
	    }  
	    if(rear == maxSize - 1)  
	{  
	      rear = -1;  
	    }  
	    /* increment rear then insert element to queue */  
	    rear++;
	    queueArray[rear] = item;  
	    currentSize++;  
	    System.out.println("Item added to queue: " + item);  
	  }  
	  /* Queue:Delete Operation */    
	  public int dequeue()  
	  {  
	    /* Checks whether the queue is empty or not */  
	    if(isQueueEmpty())  
	    {  
	      throw new RuntimeException("Queue is empty");  
	    }  
	    /* retrieve queue element then increment */  
	    int temp = queueArray[front];
	    front++;
	    if(front == maxSize)  
	    {  
	      front = 0;  
	    }  
	    currentSize--;  
	    return temp;  
	  }  
	  /* Queue:isFull Operation */   
	  public boolean isQueueFull()  
	  {  
	    return (maxSize == currentSize);  
	  }      
	  /* Queue:isEmpty Operation */   
	  public boolean isQueueEmpty()  
	{  
	    return (currentSize == 0);  
	  }  
	
	  public void printQueue()
	  {
		  System.out.println("Current queue:");
		  for(int i=front;i<=rear;i++)
		  {
			 System.out.print( queueArray[i]+ "-->");
		  }
		  System.out.println( "null");
	  }
	  public static void main(String[] args)   
	  {  
		QueueArray queue = new QueueArray(10);  
	    queue.enqueue(20);  
	    queue.enqueue(40);  
	    queue.printQueue();
	    System.out.println("Item deleted from queue: " + queue.dequeue());  
	    System.out.println("Item deleted from queue: " + queue.dequeue());  
	    queue.printQueue();
	    queue.enqueue(10);
	    queue.enqueue(11);    
	    queue.enqueue(12);    
	    queue.enqueue(13);   
	    queue.printQueue();
	    System.out.println("Item deleted from queue: " + queue.dequeue());
	    queue.printQueue();
	  }  
}
