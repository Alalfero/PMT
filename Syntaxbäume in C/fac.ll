fun doppelt(X42){
  2 * X42
}

fun fac(X1){
  if (X1<=0){1}else{X1*fac(X1-1)}
}
  
fun fib(X1){
  if(X1<=1){
    X1
  }else{
    fib(X1-2)+fib(X1-1)
  }
}

fun facIt(X2){
  X1=1;
  while(X2){
    X1=X1*X2;X2=X2-1
  };
  X1
}

