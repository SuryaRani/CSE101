void changeEntry(Matrix M, int i, int j, double x){
	if(!(size(M)>=i) && !(i>=1)){
		printf("Matrix Error: calling changeEntry() on an empty List\n");
		exit(1);
	}
	if(!(size(M)>=j) && !(j>=1)){
		printf("Matrix Error: calling changeEntry() on an empty List\n");
		exit(1);
	}

	Entry new = newEntry(j,x);
	List L = M->lists[i];
	moveFront(L);
	Entry e;
	if(index(L)!=-1){
		e = get(L);
	}
	while(index(L)!=-1){
		if(e->column >= j){
			break;
		}
		else{
			moveNext(L);
		}
	}

	if(x==0.0){
		if(e == NULL){

		}
		else{
			freeEntry(&new);
			freeEntry(&e);
			delete(L);
			M->nnz--;
		}
	}
	else{
		if(e == NULL){
			append(L,new);
			M->nnz++;

		}
		else{
			insertBefore(L,new);
			freeEntry(&e);
			delete(L);
			M->nnz++;
		}
	}