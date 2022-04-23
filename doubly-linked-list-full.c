#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */

typedef struct Node { //struct형 Node 구조체 생성
	int key; //int형 key 변수
	struct Node* llink; //struct형 포인터 llink
	struct Node* rlink; //struct형 포인터 rlink
} listNode; //listNode로 호출가능



typedef struct Head { //struct형 Node 구조체 생성
	struct Node* first; //struct형 포인터 first
}headNode; //headNode로 호출가능

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         lab3의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h); //int형 initialize함수 지정 headNode** 2중포인터를 h 매개변수로 받아옴

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
         - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h); //int형 freeList함수 지정 headNode* 포인터를 h 매개변수로 받아옴

int insertNode(headNode* h, int key); //int형 insertNode함수 지정 headNode* 포인터를 h 매개변수 받아옴, int형 key 매개변수도 받아옴
int insertLast(headNode* h, int key); //int형 insertLast함수 지정 headNode* 포인터를 h 매개변수 받아옴, int형 key 매개변수도 받아옴
int insertFirst(headNode* h, int key); //int형 insertFirst함수 지정 headNode* 포인터를 h 매개변수 받아옴, int형 key 매개변수도 받아옴
int deleteNode(headNode* h, int key); //int형 deleteNode함수 지정 headNode* 포인터를 h 매개변수 받아옴, int형 key 매개변수도 받아옴
int deleteLast(headNode* h); //int형 deleteLast함수 지정 headNode* 포인터를 h 매개변수로 받아옴
int deleteFirst(headNode* h); //int형 deleteFirst함수 지정 headNode* 포인터를 h 매개변수로 받아옴
int invertList(headNode* h); //int형 invertList함수 지정 headNode* 포인터를 h 매개변수로 받아옴

void printList(headNode* h); //void형 printList함수 지정 headNode* 포인터를 h 매개변수로 받아옴


int main()
{
	char command; //command를 받아올 char형 변수선언
	int key; //int형 key 변수선언
	headNode* headnode=NULL; //headnode포인터형 headnode를 변수선언하고 NULL로 초기화
    printf("[----- [Park Seok Won] [2017018003] -----]");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //문자받아와 command주소에 저장

		switch(command) { //command가 어떤것인지 비교
		case 'z': case 'Z': //command가 z,Z 일경우
			initialize(&headnode); //initialize함수호출 headnode주소 매계변수로 넣어준다
			break;
		case 'p': case 'P': //command가 p,P 일경우
			printList(headnode); //printList함수호출 headnode 매계변수로 넣어준다
			break;
		case 'i': case 'I': //command가 i,I 일경우
			printf("Your Key = ");
			scanf("%d", &key); //key 입력받아서 저장
			insertNode(headnode, key); //insertNode함수호출 headnode, key매개변수로 넣어준다
			break;
		case 'd': case 'D': //command가 d,D 일경우
			printf("Your Key = ");
			scanf("%d", &key); //key 입력받아서 저장
			deleteNode(headnode, key); //deleteNode함수호출 headnode, key매개변수로 넣어준다
			break;
		case 'n': case 'N': //command가 n,N 일경우
			printf("Your Key = ");
			scanf("%d", &key); //key 입력받아서 저장
			insertLast(headnode, key); //insertLast함수호출 headnode, key매개변수로 넣어준다
			break;
		case 'e': case 'E': //command가 e,E 일경우
			deleteLast(headnode); //deleteLast함수호출 headnode 매계변수로 넣어준다
			break;
		case 'f': case 'F': //command가 f,F 일경우
			printf("Your Key = ");
			scanf("%d", &key); //key 입력받아서 저장
			insertFirst(headnode, key); //insertFirst함수호출 headnode, key매개변수로 넣어준다
			break;
		case 't': case 'T': //command가 t,T 일경우
			deleteFirst(headnode); //deleteFirst함수호출 headnode 매계변수로 넣어준다
			break;
		case 'r': case 'R': //command가 r,R 일경우
			invertList(headnode); //invertList함수호출 headnode 매계변수로 넣어준다
			break;
		case 'q': case 'Q': //command가 q,Q 일경우
			freeList(headnode); //freeList함수호출 headnode 매계변수로 넣어준다
			break;
		default: //command가 위와 다른것들인경우 경고출력
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); //command가 q,Q가 아니라면 계속 반복

	return 1; //정상실행 1
}


int initialize(headNode** h) { //headNode를 생성하는 함수

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL; //h의 first를 NULL로 초기화
	return 1; //성rhd 1return
}

int freeList(headNode* h){ //list의 동적할당들을 해제하는 함수
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first; //listNode형 포인터 p는 h의 first값을 가짐

	listNode* prev = NULL; //listNode형 포인터 prev를 선언후 NULL로 초기화
	while(p != NULL) { //p가 NULL이 아니라면 계속
		prev = p; //prev의 값을 p로
		p = p->rlink; //p의 값을 p의 rlink값으로
		free(prev); //prev의 동적할당을 해제
	} //반복
	free(h); //h해드노드까지 해제
	return 0; //return 0을함
}


void printList(headNode* h) { //list를 출력하는 함수
	int i = 0; //int형 i선언후 0값 넣어줌
	listNode* p;  //lintNode형 p지정

	printf("\n---PRINT\n");

	if(h == NULL) { //h가 NULL이 아니라면
		printf("Nothing to print....\n"); //오류출력
		return;
	}

	p = h->first; //p의 값을 h의 first로 변경

	while(p != NULL) { //p가 NULL이 아니라면 계속
		printf("[ [%d]=%d ] ", i, p->key); //i번쨰에 p의 key값을 출력
		p = p->rlink; //p의 rlink값을 p에 넣어줌
		i++; //i 1증가시킴
	}//반복

	printf("  items = %d\n", i); //리스트가 몇개인지 출력
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) { //list의 마지막에 받아온 key값을 넣는 함수

	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode 포인터형 node에 listNode사이즈 동적할당
	node->key = key; //node의 key에 key값 넣어줌
	node->rlink = NULL; //node의 rlink를 NULL로 초기화
	node->llink = NULL; //node의 llink를 NULL로 초기화
 
	if (h->first == NULL) //h의 first가 NULL이라면 즉 비었다면
	{
		h->first = node; //h의 first에 node값 넣어줌
		return 0;
	}

	listNode* n = h->first; //listNode포인터형 n선언후 h의 first값 넣어줌
	while(n->rlink != NULL) { //만약 n의 rlink가 NULL이 아니라면
		n = n->rlink; //n에다가 n의 rlink값을 넣어줌
	} //반복
	n->rlink = node; //n의 rlink에 node값을 넣어줌
	node->llink = n; //node의 link에 n값을 넣어줌
	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) { //list의 마지막 노드 삭제하는 함수

	if (h->first == NULL) //만약 h의 first가 NULL이라면 즉 비었다면
	{
		printf("nothing to delete.\n"); //지울것이 없다는 오류출력
		return 0;
	}

	listNode* n = h->first; //listNode형 포인터 n에 h의 first를 넣어줌
	listNode* trail = NULL; //listNode형 포인터 trail을 NULL로 초기화시킴

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->rlink == NULL) { //만약 n의 rlink가 NULL이라면
		h->first = NULL; //h의 first도 NULL로 초기화
		free(n); //n의 동적할당을 해제
		return 0;
	}

	/* 마지막 노드까지 이동 */
	while(n->rlink != NULL) { //n의 rlink가 NULL일경우
		trail = n; //trail에 n값을 넣어주고
		n = n->rlink; //n의 rlink값을 n에 넣어줌
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->rlink = NULL; //trail의 rlink값을 NULL로 초기화함
	free(n); //n의 동적할당을 free시켜줌

	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) { //처음에 key값을 가진 노드 추가해주는 함수

	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode형 node 포인터 선언후 listNode사이즈로 동적할당 해줌
	node->key = key; //node의 key에 key값을 넣어줌
	node->rlink = node->llink = NULL; //node의 rlink에 node의 llink값을 넣어줌 llink값은 NULL인 상태로 (둘다 NULL로 초기화 한다는 뜻)

	if(h->first == NULL) //만약 h의 first가 NULL이라면
	{
		h->first = node; //h의 first에 node값을 넣어줌
		return 1;
	}

	node->rlink = h->first; //node의 rlink에 h의 first값을 넣어줌
	node->llink = NULL; //node의 llink에 NULL값을 넣어줌

	listNode *p = h->first; //listNode형 포인터 p에 h의 first값을 넣어줌
	p->llink = node; //p의 link에 node값을 넣어주고
	h->first = node; //h의 first에 node값을 넣어줌

	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) { //첫번째 노드 삭제하는 함수

	if (h->first == NULL) //만약 h의 first가 NULL이라면
	{
		printf("nothing to delete.\n"); 
		return 0;
	}
	listNode* n = h->first; //listNode형 포인터 n선언후 h의 first값을넣어줌
	h->first = n->rlink; //h의 first에 n의 rlink값을 넣어줌

	free(n); //n에 동적할당을 초기화시킴

	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) { //리스트의 링크를 역순으로 배치


	if(h->first == NULL) { //리스트가 비었다면
		printf("nothing to invert...\n"); //정렬할것이 없다는 오류출력
		return 0;
	}
	listNode *n = h->first; //listNode형 n포인터에 h의 first값을 넣어줌
	listNode *trail = NULL; //listNode형 trail포인터에 NULL값으로 초기화
	listNode *middle = NULL; //listNode형 middle포인터 NULL값으로 초기화

	while(n != NULL){ //만약 n이 NULL이 아니라면
		trail = middle; //trail을 middle로
		middle = n; //middle을 n으로
		n = n->rlink; //n을 n의 rlink로
		middle->rlink = trail; //middle의 rlink를 trail로
		middle->llink = n; //middle의 llink를 n으로 만들음
	}

	h->first = middle; //h의 first를 middle로 만듬

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) { 
 
	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode포인터 node를 동적할당
	node->key = key; //node의 key에 key값 넣어줌
	node->llink = node->rlink = NULL; //node의 llink에 node의 rlink 값넣어줌 rlink값은 NULL임 (둘다 NULL로 초기화한다는뜻)

	if (h->first == NULL) //만약 h의 first가 NULL이라면
	{
		h->first = node; //h의 first에 node값을 넣어줌
		return 0;
	}

	listNode* n = h->first; //listNode형 n에 h의 first값을 넣어줌

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) { //n이 NULL이 아니라면 반복
		if(n->key >= key) { //n의 key값이 key보다 크거나 같을경우
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) { //n이 h의 fisrt랑 같을경우
				insertFirst(h, key); //insertFirst함수 출력
			} else { /* 중간이거나 마지막인 경우 */
				node->rlink = n; //node의 rlink에 n값 넣어줌
				node->llink = n->llink; //node의 llink에 n의 llink값 넣어줌
				n->llink->rlink = node; //n의 llink의 rllink에 node값을 넣어줌
			}
			return 0;
		}

		n = n->rlink; //n에 n의 rlink값을 넣어줌
	}

	/* 마지막 노드까지 찾지 못한 경우, 마지막에 삽입 */
	insertLast(h, key); //insertLast함수 호출
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) { //노드를 삭제하는 함수

	if (h->first == NULL) //h의 first가 NULL이라면
	{
		printf("nothing to delete.\n"); //아무것도 없어서 삭제할수 없다는 오류 출력
		return 1;
	}

	listNode* n = h->first; // listNode포인터 n에 h의 first값 넣어줌

	while(n != NULL) { //만약 n의 값이 NULL이 아니라면 반복
		if(n->key == key) { //만약 n의 key값이 key랑 같을경우
			if(n == h->first) { /* 첫 노드째 노드 인경우 */ 
				deleteFirst(h); //deleteFirst함수 호출해서 삭제함
			} else if (n->rlink == NULL){ /* 마지막 노드인 경우 */
				deleteLast(h); //deleteFirst함수 호출해서 삭제함
			} else { /* 중간인 경우 */
				n->llink->rlink = n->rlink; //n의 llink의 rlink의 값을 n의 rlink로
				n->rlink->llink = n->llink; //n의 rlink의 llink의 값을 n의 llink로 변경시켜줌
				free(n); //연결되지 않은 n노드 동적할당 해제
			}
			return 1;
		}

		n = n->rlink; //n의 값을 n의 rlink로 변경
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key); //key값을 가진 노드가 없다는 오류출력
	return 1;
}


