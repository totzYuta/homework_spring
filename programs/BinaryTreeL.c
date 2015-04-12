/*
 * 春課題 II' : 二分探索木ループ版
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *left;
  struct node *right;
} Node;

/* Node の作成 */
Node *
newNode(int n) {
  Node* obj;
  obj = (Node *)malloc(sizeof(Node));
  obj->value = n;
  obj->left = NULL;
  obj->right = NULL;
  return obj;
}


/* Node の追加 */
Node *
addNode(Node* obj, int n) {
  Node *iobj;

  /* obj が NULL の場合 */
  if (obj == NULL) {
    return newNode(n);
  }

  iobj = obj;

  while (1) {
    /* 追加する場所を探して追加 */
    if (iobj->value == n) { 
      break;       /* 追加しない */
    } else if (iobj->value < n) {
      if(iobj->right == NULL){
        iobj->right = newNode(n); // (10)
        break;
      } else {
        iobj = iobj->right;
      }
    } else { /* obj->value > n の時 */
      if (iobj->left == NULL) {
        iobj->left = newNode(n);
        break;
      } else {
        iobj = iobj->left;
      }
    }
  }
  return obj;
} /* end of addNode */


/* Node の削除（指定された Node を削除）*/
Node *
deleteThisNode(Node *obj) {
  Node *tmpobj;
  Node *iobj;

  if (obj == NULL) return NULL;
  if (obj->left == NULL) {
    tmpobj = obj->right;
    free(obj);
  } else if (obj->right == NULL) {
    tmpobj = obj->left;
    free(obj);
  } else {
    /* 右の子供たちのつけかえ */
    tmpobj = obj->left;
        
    iobj = tmpobj;
    while (iobj->right != NULL) {
      iobj = iobj->right;
    }
    iobj->right = obj->right; // (11)
    free(obj);
  }
  return tmpobj;
}

/* Node の削除 */
Node *
deleteNode(Node *obj, int n) {
  Node *pobj;

  if (obj->value == n) {/* obj が該当 Node だった時 */
    obj = deleteThisNode(obj);
    return obj;
  } else {

    pobj = obj;
    while (1) {
      if (pobj->value < n) {
        if (pobj->right == NULL) {
          break; /* 該当なし */
        } else {
          if (pobj->right->value == n) {
            pobj->right = deleteThisNode(pobj->right); // (12)
            break;
          } else {
            pobj = pobj->right;
          }
        }
      } else { /* n < pobj->value */

        if (pobj->left == NULL) {
          break; /* 該当なし */
        } else {
          if (pobj->left->value == n) {
            pobj->left = deleteThisNode(pobj->left);
            break;
            pobj = pobj->left; // (13)
          }
        }
      } /* end of n < pobj->vlaue */
    }

  }
}


/* Node の表示 */
void 
printNodes(Node *obj) {
  if (obj != NULL) {
    if (obj->left != NULL) {
      printNodes(obj->left);
    }

    printf("%d\t", obj->value);

    if (obj->right != NULL) {
      printNodes(obj->right);
    }
  }

}

int
main(int argc, char *argv[]){
  Node *topnode = NULL;

  topnode = addNode(topnode, 5);
  topnode = addNode(topnode, 7);
  topnode = addNode(topnode, 1);
  topnode = addNode(topnode, -1);
  topnode = addNode(topnode, 4);
  topnode = addNode(topnode, 10);
  
  printNodes(topnode);
  printf("\n");

  topnode = deleteNode(topnode, 5);

  printNodes(topnode);

}
