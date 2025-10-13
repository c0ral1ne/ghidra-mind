
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(void)

{
  undefined4 uVar1;
  
  setvbuf(_stdout,(char *)0x0,2,0);
  setvbuf(_stdin,(char *)0x0,2,0);
  alarm(0x3c);
  hint();
  init_ABCDEFG();
  uVar1 = seccomp_init(0);
  seccomp_rule_add(uVar1,0x7fff0000,0xad,0);
  seccomp_rule_add(uVar1,0x7fff0000,5,0);
  seccomp_rule_add(uVar1,0x7fff0000,0x127,0);
  seccomp_rule_add(uVar1,0x7fff0000,3,0);
  seccomp_rule_add(uVar1,0x7fff0000,4,0);
  seccomp_rule_add(uVar1,0x7fff0000,0xfc,0);
  seccomp_load(uVar1);
  ropme();
  return;
}

