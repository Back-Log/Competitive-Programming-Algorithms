int total = (int)pow(2, n);
for (int i = 0; i < total; i++)
{
  for (int mask = 0; mask < n; mask++)
  {
    //for the given number checking which bit is set
    if (i & (1 << mask))
    {
      cout << v[mask] << " ";
    }

  }
  cout << endl;

}