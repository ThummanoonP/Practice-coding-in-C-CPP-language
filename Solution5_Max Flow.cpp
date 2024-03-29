/*
LANG: C++
TASK: Maxflow
*/

#include<stdio.h>
#define MAXSIZE 100
#define INFINITY 2000000
int N, NumEdge ;


//Edge.
typedef struct _EDGE{
  int begin, end ;
  int cap ;
  inunol�w ;     
  
  void addEdge(int u, int v, int c){
    begin = u ;
    end = v ;
    cap = c ;
    flow = 0 ;
    return ;
  }
  
  int capInfo(){
      return cap ;
  }

  int flowInfo(){
      return flow ;    
  }  
  
  bool isBeginOfThisEdge(int node){
       if(node == begin)
         return true ;
       else
         return false ;
  }
  
  int otherOfThisEdge(int node){
      if( isBeginOfThisEdge(node) )
        return end ;
      else
        return begin ; 
  }
  
  int capRto(int node){
       if( isBeginOfThisEdge(node) )
         return flow ;
       else
         return cap - flow ;
  }
  
  void addFlowRto(int node, int d){
      if( isBeginOfThisEdge(node) )
        flow = flow - d ;
      else
        flow = flow + d ;
      return ;
  }
  
}EDGE ;

//Queue.
typedef struct _QUEUE{
 
 int front, rear, memberSize ;
 int data[MAXSIZE] ;       
 
 void NewQueue(){
   front = 0 ;
   rear = 0 ;
   memberSize = 0 ;
 
   return ;
 }
 
 void Enqueue(int tmp){
   if( !isFull() ){
    data[rear] = tmp ;
    rear++ ;
    if(rear > MAXSIZE*(MAXSIZE - 1))
     rear = 0 ;
    memberSize++ ;
    return ;
   }
   else
    return ;
 }
 int Dequeue(){
  int tmp ;
  if( !isEmpty() ){
    tmp = data[front] ;
    front++ ;
    if(front > MAXSIZE)
     front = 0 ;
    memberSize-- ;
    return tmp ;
  }
  else
    return -1 ;
    
 }
 
 bool isEmpty(){
  if(memberSize <= 0)
    return true ;
  else
    return false ;  
 }
 
 bool isFull(){
  if(memberSize >= MAXSIZE)
    return true ;
  else
    return false ;  
 }
 
}QUEUE ;


typedef struct _COLLECTION{
 EDGE *data[MAXSIZE*(MAXSIZE - 1)];
 int membersize, memberIndex ;
 void NewCollection(){
   membersize = 0 ;
   memberIndex = 0 ;
   return ;     
 }
 
 void addMember(EDGE *tmp){
   data[membersize] = &(*tmp) ; /* &(*tmp) means to get address that tmp pointed 
   and keep it in other pointer. In this is data. */
   membersize++ ;
   return ;     
 }
 
 bool hasNext(){
   if(membersize > 0 && memberIndex < membersize)
     return true ;
   else
     return false ;
 }
 
 EDGE *Next(){
   EDGE *tmp ;
   tmp = &(*data[memberIndex]) ;
   memberIndex++ ;
   return &(*tmp) ;     
 }
 
}COLLECTION ;

EDGE edge[MAXSIZE*(MAXSIZE - 1) + 1];
EDGE *pred[MAXSIZE*(MAXSIZE - 1) + 1] ; /* path s-t. Or for keeping A SET 
OF EDGES that is the best path from source to sink. */


// end--------------------------------------------------------------------------

// Min Funtions.
int Min(int a, int b){
    if(a < b)
      return a ;
    else
      return b ;
}
// end--------------------------------------------------------------------------

// Find Neightbors.
void neightborOfNode(COLLECTION *tmp, int Node){
  int i ;
  
  for(i = 1 ; i <= NumEdge ; i++){
      if(Node == edge[i].begin)
        tmp->addMember( &edge[i] );
  }
  return ;    
}
// end--------------------------------------------------------------------------

// Find the best path s-t BY Shortest Augmenting Path.
bool augpath(int Source, int Sink){
     
   // v = begin node, w = end node, wt = Distance.
   int i, v, w, wt[Sink + 1] ;
   
   // First Time, Clear Old Path and Assign distance of Node at begining to INFINITY.
   for(i = Source ; i <= Sink ; i++){
     pred[i] = NULL ;
     wt[i] = INFINITY ;
   }
   QUEUE q ;             // Queue of Node.
   COLLECTION c ;        // use set instead of Interator.
   q.NewQueue() ;

   //First time for adding neighbors of Source.
   c.NewCollection() ;
   q.Enqueue(Source) ;
   wt[Source] = 0 ; /* define distance(capacity) at Node 1 as 0. or can means 
   best answer from Node 1 to Node 1 (at Node 1) in dynamic programming */

   while(q.isEmpty() != true ){
     v = q.Dequeue() ;
     //Clear old Collection                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       