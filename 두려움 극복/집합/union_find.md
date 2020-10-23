# union find (disjoint set)
- 여러 개의 노드가 있을 때 두 개의 노드를 선택해서 두 노드가 동일한 집합에 있는지 확인.

## 구현 방법
### 1. 초기 부모노드는 자기 자신
```
int parent[n+1];

for(int i=1;i<=n;i++)
  parent[i] = i;
```

### 2. getParent
해당 노드의 최상위 부모를 찾는다. 재귀함수를 활용한다.   
자기 자신과 같은 최상위 노드일 때 return하고, 그렇지 않을 때 해당 노드의 부모에 대해 함수를 다시 실행한다.

```
int getParent(int node) {
  if(parent[node]==node) return node;
  return parent[node] = getParent(parent[node]);
}
```

### 3. unionParent
두 노드의 부모를 합친다. 부모의 값이 더 작은 노드를 부모로 설정한다.

```
void unoonParent(int n1, int n2){
  n1 = getParent(n1);
  n2 = getParent(n2);
  if(n1<n2) parent[n2] = n1;
  else parent[n1] = n2;
}

```

재귀함수 때문에 저게 어떻게 돌아가는 지 헷갈리는 알고리즘...   
내 부모를 가지고 다시 부모를 찾아줘.. 라는 걸 기억하자.   
서로의 연결관계에 대해 주어질 때 두 노드에 대해서 합쳐주면 된다.   

같은 집합에 속햇는지, 갈 수 있는 경로인지 등을 알 수 있다.
