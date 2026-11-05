Count Sort

```

A [ 2 1 3 6 5 8 ]

get_max = max(A) = 5

cntArr[get_max + 1] = {0}

cntArr [ 0 0 0 0 0 0 ]

cntArr[A[i]]++

cntArr [ 0 1 1 1 0 1 1 0 1 ]

cntArr[i] = cntArr[i - 1] + cntArr[i]

cntArr [ 0 1 2 3 3 4 5 5 6 ]

ans[len(A)]

ans [  , , , , ,  ]

ans[cntArr[A[i]] - 1] = A[i]        // traverse in reverse order to maintain stability
cntArr[A[i]]--



A      [ 2 1 3 6 5 8 ]
cntArr [ 0 1 1 1 0 1 1 0 1 ]
cntArr [ 0 1 2 3 3 4 5 5 6 ]
ans    [             ]


A      [ 2 1 3 6 5 8 ]
                   ^
cntArr  [ 0 1 2 3 3 4 5 5 6 ]         ans[6 - 1] = 8
                          ^                  
ans    [           8 ]


A      [ 2 1 3 6 5 8 ]
                 ^
cntArr [ 0 1 2 3 3 4 5 5 5 ]          ans[4 - 1] = 5
                   ^                  
ans    [       5    8 ]


A      [ 2 1 3 6 5 8 ]
               ^
cntArr [ 0 1 2 3 3 3 5 5 5 ]          ans[5 - 1] = 6
                     ^                  
ans    [       5 6  8 ]


A      [ 2 1 3 6 5 8 ]
             ^
cntArr [ 0 1 2 3 3 3 4 5 5 ]          ans[3 - 1] = 3
               ^                  
ans    [     3 5 6  8 ]


A      [ 2 1 3 6 5 8 ]                
           ^
cntArr [ 0 1 2 2 3 3 4 5 5 ]          ans[1 - 1] = 1
           ^                  
ans    [ 1   3 5 6  8 ]


A      [ 2 1 3 6 5 8 ]
         ^
cntArr [ 0 0 2 2 3 3 4 5 5 ]          ans[2 - 1] = 2
             ^                  
ans    [ 1 2 3 5 6  8 ]


A      [ 2 1 3 6 5 8 ]
       ^
cntArr [ 0 0 1 2 3 3 4 5 5 ]
             ^                  
ans    [ 1 2 3 5 6 8 ]


```