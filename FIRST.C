int x=10;

main() {
  int x=3;
  printf("%d", f(x));
  return 0;
}

int f(int w) {
  x=x+1;
  g(w);
  return 0;
}

int g(int x) {
  x=x+1;
  h(x);
  return(x);
}

int h(int x) {
  x = x+1;
  return 0;
}
