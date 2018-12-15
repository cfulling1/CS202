unsigned short int reverse(unsigned short int x) {
  return (x>>8) | (x<<8);
}
