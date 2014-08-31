static bool isRangeOk(const Stack *p, int val) {
  return !p->needRangeCheck || (p->min <= val && val <= p->max);
}

bool push(Stack *p, int val) {
  if(!isRangeOk(p->Range, val) || isStackFull(p)) return false;
  p->pBuf[p->top++] = val;
  return true;
}
