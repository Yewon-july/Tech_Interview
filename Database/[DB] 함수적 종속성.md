### 함수적 종속(Functional Dependency)

**함수적 종속**이란 어떤 릴레이션 R이 있을 때 X와 Y를 각각 속성의 부분집합이라고 가정해보자. 여기서 X의 값을 알면 Y의 값을 바로 식별할 수 있고, X의 값에의해 Y의 값이 달라질 때, **Y는 X에 함수적 종속**이라고 한다. 이 경우 **X를 결정자**, **Y를 종속자**라고 하며, **X→Y**로 표현할 수 있다.



### 완전 함수적 종속(Full Functional Dependency)

**완전 함수적 종속**이란, 종속자가 **기본키에만 종속**되며, 기본키가 여러 속성으로 구성되어 있을 경우, 기본키를 구성하는 **모든 속성이 포함된 기본키의 부분집합에 종속**된 경우이다.

| <u>사원번호</u> | 이름   | 나이 |
| --------------- | ------ | ---- |
| E001            | 홍길동 | 24   |
| E002            | 김철수 | 25   |

이 릴레이션에서 기본키는 "사원번호" 속성이다. 이름, 나이는 사원번호를 알아야 식별 가능하다. 따라서 이름, 나이는 사원번호에 **완전 함수 종속**된 관계이다.



| <u>사원번호</u> | <u>상품번호</u> | 주문상품 | 수량 | 가격  |
| --------------- | --------------- | -------- | ---- | ----- |
| E001            | P001            | 노트북   | 1    | 10000 |
| E001            | P002            | 모니터   | 1    | 500   |

이 릴레이션에서 기본키는 사원번호와 상품번호로 구성되어 있다. 여기서 수량은 기본키를 구성하는 사원번호와 상품번호 속성을 모두 알아야 식별할 수 있다. 따라서 수량은 기본키에 완전 함수 종속된 관계이다.



### 부분 함수적 종속(Partial Functional Dependency)

부분 함수적 종속이란, 릴레이션에서 종속자가 기본키가 아닌 다른 속성에 종속되거나, 기본키가 여러 속성으로 구성되어 있을 경우 기본키를 구성하는 속성 중 일부에만 종속되는 경우이다.

| <u>사원번호</u> | <u>상품번호</u> | 주문상품 | 수량 | 가격  |
| --------------- | --------------- | -------- | ---- | ----- |
| E001            | P001            | 노트북   | 1    | 10000 |
| E001            | P002            | 모니터   | 1    | 500   |

이 릴레이션에서 주문상품은 상품번호만 알아도 식별할 수 있기에, 주문상품 속성은 기본키에 부분 함수적 종속된 관계이다.



### 이행적 함수 종속(Transitive Functional Dependency)

릴레이션에서 X, Y, Z라는 3 개의 속성이 있을 때, X→Y, Y→Z이란 종속관계가 있을 경우, X→Z가 성립될 때 이행적 함수 종속이라 한다. 즉, X를 알면 Y를 알고 그를 통해 Z를 알 수 있는 경우를 말한다.

| <u>사원번호</u> | 이름   | 나이 |
| --------------- | ------ | ---- |
| E001            | 홍길동 | 24   |
| E002            | 김철수 | 25   |

이 릴레이션에서 사원번호를 알면 이름을 알 수 있고, 이름을 알면 나이를 알 수 있다. 따라서 사원번호를 알면 나이를 알 수 있으므로 이행적 함수 종속 관계이다.



### 종속성 집합 F의 최소 커버(최소 집합) 요건

1. F 내의 모든 종속성이 오른쪽에 하나의 속성만을 가지고 있어야 한다.
2. F와의 동등성을 유지하기 위해서는 F로부터 어떤 함수적 종속성도 제거될 수 없다.
3. F에서 X→A를 X의 진부분집합 Y에 대하여 Y→A로 교체했을 때, F와 동등한 함수적 종속들의 집합이 될 수 없다.