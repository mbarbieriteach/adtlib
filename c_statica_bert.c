void shift(int[] v, int max)
{
  for(int i=0; i < max; i++)
    V[i] = v[i+1];
}

int dequeue(int[] v, int max, int l)
{
  int tmp = v[0];
  shift(v, max);
  return tmp;
}

int enqueue(int[] v, int max, int dato, int l)
{
  if(l == max)
    return 0;
  v[l] = dato;
}
