//Gruppo Marini_Simonetto_Biasia...
void shift(int V[],int max,int *l){
  for(int i=0;i<max-1,i++)
    V[i]=V[i+1];
  l--;
}
int dequeue(int V[],int max,int *l){
  int tmp=V[0];
  if(l>0){
    shift(V,max,l);
    return tmp;
  }
  return 0;
}
int enqueue(int V[],int max,int dato,int* l){
  if(l==max)
    return 1;
  V[l]=dato;
  return 0;
}
