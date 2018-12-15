ptr=head;
ptr2=ptr;
ptr=ptr->link; //ptr is ahead one link

if(ptr->link!=NULL) {
  ptr2=ptr->link;
  ptr=ptr->link;
}

else {
  ptr2->link=NULL;
  free(ptr);
}
