grade <- function(x) {
  if(x>90) return ("A")
  if(x>80) return ("B")
  if(x>70) return ("C")
  if(x>60) return ("D")
  return ("E")
}