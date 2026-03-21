

  while(m--){
    int x1,y1,x2,y2;

    cin >> x1>>y1>>x2>>y2;

    int value = dp[y2][x2] - dp[y1-1][x2] -dp[y2][x1-1] + dp[y1-1][x1-1];

    cout << value << '\n';
  }
