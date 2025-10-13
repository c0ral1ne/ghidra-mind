
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void func(int param_1)

{
  __gid_t __egid;
  __gid_t __rgid;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("overflow me : ");
  gets(local_30);
  if (param_1 == -0x35014542) {
    __egid = getegid();
    __rgid = getegid();
    setregid(__rgid,__egid);
    system("/bin/sh");
  }
  else {
    puts("Nah..");
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
    __stack_chk_fail_local();
  }
  return;
}

