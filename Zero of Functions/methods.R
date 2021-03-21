f <- function(x){
  return (x^2 - 3*x - exp(x) + 2)
}

ex = expression(x^2 - 3*x - exp(x) + 2)

derivada <- function(x){
  
  ff <- D(ex, "x")
  return (eval(ff))
}

# Metodo Bissecção
bisseccao <- function(a, b, epsolon = 10^(-2)){
  n = 0
  x <- 0 
  repeat{
    n <- n + 1
    x <- (a+b)/2
    fa <- f(a)
    fb <- f(b)
    fx <- f(x)
    
    print(paste0("x", n, " = ", format(x, digits = 6)))
    
    if(n > 100){
      print("There's something wrong\n")
      break
    }
    if( abs(fx) <= epsolon){
      break;
    } else if( f(x)*f(a) < 0){
      b <- x
    } else{
      a <- x
    }
  }
  print(paste("Number of iterations: ", n));
  return (x)
}

# Metodo Falsa posição (Regula Falsi)
regulaFalsi <- function(a, b, epsolon = 10^(-2)){
  n = 0
  x <- 0
  repeat{
    n <- n+1
    fa <- f(a)
    fb <- f(b)
    
    x <- ( a * fb - b * fa ) / ( fb - fa )
    
    fx <- f(x)
    
    print(paste0("x", n, " = ", format(x, digits = 6)))
    
    if(n > 100){
      print("There's something wrong\n")
      break
    }
    
    if(abs(fx) <= epsolon){
      break
    } else if(fx*fa < 0){
      b <- x
    }else{
      a <- x
    }
  }
  
  print(paste("Number of iterations: ", n));
  return (x)
  
}

#Metodo de Newton-Raphson
newtonRaphson <- function(x0, epsolon = 10^-2){
  n <- 0
  x <- 0
  
  repeat{
    n <- n + 1
    fx0 <- f(x0)
    derivadafx0 <- derivada(x0)
    
    x <- x0 - (fx0 / derivadafx0)
    
    fx <- f(x)
    
    print(paste0("x", n, " = ", format(x, digits = 6)))
    
    if(n > 100){
      print("There's something wrong\n")
      break
    }
    
    if(abs(fx) < epsolon)
      break
    
    x0 <- x
  }
  
  print(paste("Number of iterations: ", n));
  return (x)
  
}

#Metodo da Secante
secante <- function(x0, x1, epsolon = 10^(-2)){
  n <- 0
  x <- 0
  repeat{
    n <- n + 1
    fx0 = f(x0)
    fx1 = f(x1)
    
    x <- ( (x0 * fx1) -( x1 * fx0) ) / ( fx1 - fx0 )
    
    fx <- f(x)
    
    print(paste0("x", n, " = ", format(x, digits = 6)))
    
    if(n > 100){
      print("There's something wrong\n")
      break
    }
    
    if(abs(fx) < epsolon)
      break
    
    x0 <- x1
    x1 <- x
  }
  
  print(paste("Number of iterations: ", n));
  return (x)
}
