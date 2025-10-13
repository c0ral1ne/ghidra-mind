/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void B(void)

{
  printf("You found \"Marvolo Gaunt\'s Ring\" (EXP +%d)\n",b);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void C(void)

{
  printf("You found \"Helga Hufflepuff\'s Cup\" (EXP +%d)\n",c);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void A(void)

{
  printf("You found \"Tom Riddle\'s Diary\" (EXP +%d)\n",a);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void D(void)

{
  printf("You found \"Salazar Slytherin\'s Locket\" (EXP +%d)\n",d);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void E(void)

{
  printf("You found \"Rowena Ravenclaw\'s Diadem\" (EXP +%d)\n",e);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void G(void)

{
  printf("You found \"Harry Potter\" (EXP +%d)\n",g);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.ax replaced with injection: get_pc_thunk_ax */

void F(void)

{
  printf("You found \"Nagini the Snake\" (EXP +%d)\n",f);
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void hint(void)

{
  puts("Voldemort concealed his splitted soul inside 7 horcruxes.");
  puts("Find all horcruxes, and destroy it!\n");
  return;
}
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
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void init_ABCDEFG(void)

{
  ssize_t sVar1;
  int iVar2;
  uint local_14;
  int local_10;
  
  local_10 = open("/dev/urandom",0);
  sVar1 = read(local_10,&local_14,4);
  if (sVar1 != 4) {
    puts("/dev/urandom error");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  close(local_10);
  srand(local_14);
  iVar2 = rand();
  a = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  iVar2 = rand();
  b = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  iVar2 = rand();
  c = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  iVar2 = rand();
  d = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  iVar2 = rand();
  e = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  iVar2 = rand();
  f = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  iVar2 = rand();
  g = iVar2 * -0x21524111 + (uint)(0xcafebabd < (uint)(iVar2 * -0x21524111)) * 0x35014542;
  sum = g + a + b + c + d + e + f;
  return;
}
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 ropme(void)

{
  int iVar1;
  ssize_t sVar2;
  char local_78 [100];
  int local_14;
  int local_10;
  
  printf("Select Menu:");
  __isoc99_scanf(&DAT_08042151,&local_14);
  getchar();
  if (local_14 == a) {
    A();
  }
  else if (local_14 == b) {
    B();
  }
  else if (local_14 == c) {
    C();
  }
  else if (local_14 == d) {
    D();
  }
  else if (local_14 == e) {
    E();
  }
  else if (local_14 == f) {
    F();
  }
  else if (local_14 == g) {
    G();
  }
  else {
    printf("How many EXP did you earned? : ");
    gets(local_78);
    iVar1 = atoi(local_78);
    if (iVar1 == sum) {
      local_10 = open("/home/horcruxes_pwn/flag",0);
      sVar2 = read(local_10,local_78,100);
      local_78[sVar2] = '\0';
      puts(local_78);
      close(local_10);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    puts("You\'d better get more experience to kill Voldemort");
  }
  return 0;
}