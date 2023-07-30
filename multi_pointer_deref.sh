#!/bin/bash 

#  stap -gu -c ./cc_deref cc_deref.stp -gu参数，这个参数是嵌入C代码必须的参数

sudo stap -gu -e '

function deref:long(ptr:long)
%{
    STAP_RETURN(*(char **)STAP_ARG_ptr); 
%}

probe begin {
printf("hello\n")
}

probe process("'${PWD}'/multi_pointer_deref").function("func").call
{
    printf("-------------------------------------------------------------\n");
    printf("$$vars: %s\n", $$vars);
     printf("$pstr: %p, user_string($pstr): %s\n", $pstr, user_string($pstr));
     printf("$ppstr: %p, user_string($ppstr): %s, user_string(deref($ppstr)): %s\n", $ppstr, user_string($ppstr), user_string(deref($ppstr)));

   //pt1 = $pt;
   //pt2 = deref($ppt);
   //pt3 = deref(deref($pppt));

   //printf("pt1: %p, pt2: %p, pt3: %p\n", pt1, pt2, pt3);
   //printf("$pt=>a: %s, $pt->a: %s, $pt->b: %d\n", user_string(@cast($pt, "struct test")->a), user_string($pt->a), $pt->b);
   //printf("pt1=>a: %s, pt1->b: %d\n", user_string(@cast(pt1, "struct test")->a), pt1->b);
   //printf("$ppt=>a: %s, $ppt->a: %s, $ppt->b: %d\n", user_string(@cast($ppt, "struct test")->a), user_string($ppt->a), $ppt->b);
   //printf("pt2=>a: %s, pt2->b: %d\n", user_string(@cast(pt2, "struct test")->a), @cast(pt2, "struct test")->b);
   //printf("$pppt=>a: %s, $pppt->a: %s, $pppt->b: %d\n", user_string(@cast($pppt, "struct test")->a), user_string($pppt->a), $pppt->b);
   //printf("pt3=>a: %s, pt3->b: %d\n", user_string(@cast(pt3, "struct test")->a), @cast(pt3, "struct test")->b);

    printf("-------------------------------------------------------------\n");

    exit();
}'
