
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

