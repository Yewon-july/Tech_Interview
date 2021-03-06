### 인터넷 계층이란?

- TCP/IP의 3번째 계층으로, 송신자의 IP 주소와 수신자의 IP 주소를 읽어서 경로를 결정하거나 전송하는 역할을 수행한다.

### 인터넷 계층 기능

- 경로 설정(Routing): 경로를 설정
- Point to Point packet 전달
- **논리 주소 지정**
- **주소 변환**

```
*데이터 그램이란?
기존 패킷(Packet)에 IP Header을 붙이는 것
```



### 라우팅

- 라우팅은 IP 헤더에 있는 목적지 IP 주소를 읽어서 경로를 결정하는 작업이다. 라우팅의 방법에는 사전에 고정한 정적 경로(Static Routing) 방법이 있고, 네트워크의 상태를 파악해서 최적의 경로를 결정하는 동적 경로(Dynamic Routing) 방법이 있다. 



#### 라우팅 경로 고정 여부에 따른 라우팅 방법 종류

| 라우팅 방법 | 내용                                                         |
| ----------- | ------------------------------------------------------------ |
| 정적 경로   | - 관리자가 직접 라우팅 테이블의 경로를 설정, 경로가 고정적이며, 수동 갱신하는 방식<br>- 기법: Floating Static routing 등 |
| 동적 경로   | - 네트워크 관리자의 개입없이 네트워크 상황 변화에 따라 인접 라우터 간에 자동으로 경로 정보를 교환하도록 설정<br>- 경로 정보를 교환하여 최적의 경로를 결정 및 상황에 따른 능동 대처가 가능<br>- 기법: Distance Vector routing, Link State routing |



- 라우팅 프로토콜은 경로를 결정하는 알고리즘을 포함한 프로토콜이다. 라우팅 프로토콜은 한 도메인 내에서 경로를 결정하는 IGP(Internal Gateway routing Protocol)와 도메인 간에 경로를 결정하는 EGP(Exterior Gateway routing Protocol)로 분류ehlsek.

#### 라우팅 범위에 따른 라우팅 프로토콜 종류

| 라우팅 프로토콜 | 내용                                               |
| --------------- | -------------------------------------------------- |
| IGP             | 동일 그룹(기업 또는 ISP) 내에서 라우팅 정보를 교환 |
| EGP             | 다른 그룹과 라우팅 정보를 교환                     |



- 라우팅 프로토콜 중에서 **Distance Vector**는 경로를 결정할 때 통과해야 하는 **라우터의 수**가 적은 쪽으로 경로를 결정하는 방법이다. 일명 홉 카운트(Hop Count) 또는 TTL(Time To Live)이라고 한다. 이는 도로에서 교차로가 적은 경우 빠르게 도착하는 이유와 같은 것이다. Distance Vector에는 RIP, IGRP, EIGRP, BGP 프로토콜이 존재한다.
- 라우팅 프로토콜 중 **Link State**는 넽워크 대역폭, 지연정보 등을 종합적으로 고려해 **Cost를 산정**하고 해당 Link의 Cost에 따라 경로를 결정하는 방법으로 대표적으로 OSPF가 있다. 이러한 기법은 주기적으로 지연과 같은 정보를 라우터 간에 공유해야 하고 이것은 라우터 브로드캐스트를 통해서 공유한다. OSPF는 라우터들을 **트리 형태의 자료구조처럼 연결**하고 라우터 간에 정보를 공유한다. OSPF는 **대규모 네트워크** 에서 사용되는 라우팅 프로토콜이고 구조가 복잡한 특성이 있다.

#### Distance Vector 방식과 Link State 방식 차이점

| 구분          | Distance Vector                                              | Link State                                                   |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 알고리즘      | 최단 경로를 구하는 벨만 포드(Bellman-Ford) 알고리즘 기반     | 최소 신장 트리를 구하는 다익스트라(Dijkstra) 알고리즘 기반   |
| 동작 원리     | 네트워크 변화 발생 시 해당 정보를 인접한 라우터에 정기적으로 전달하고, 인접 라우터에서는 라우팅 테이블에 정보 갱신 | - 라우터와 라우터를 연결하는 Link 상태에 따라 최적의 경로 설정<br>- 라우터가 네트워크 변화 감지 시 링크 상태 변경 정보를 인접한 라우터에게 즉각 전달하고 이를 저장함. |
| 라우팅 정보   | 모든 라우터까지의 거리 정보 보관                             | 인접 라우터까지의 Link Cost 계산                             |
| 정보전송 시점 | 일정주기(30초, 이웃 라우터와 공유)                           | 변화 발생 시에만                                             |
| 대표 프로토콜 | RIP, IGRP, EIGRP(내부 라우팅), BGP                           | - OSPF(가장 많이 사용됨)<br>- IS-IS(소규모 N/W에서 사용)     |
| 단점          | - 변화되는 라우팅 정보를 모든 라우터에 주기적으로 갱신하므로 망 자체의 트래픽을 유발<br>- 라우팅 정보를 변경하는 문제 발생 시 Routing Loop가 발생할 가능성이 있음 | - 네트워크 전체 정보 유지를 위한 많은 메모리 소요<br>- 라우터의 CPU 사용량이 많아짐<br>- 라우터간 회선의 대역차이로 동기화 실패할 가능성 있음. |



### RIP(Routing Information Protocol)

| 구분        | 내용                                                         |
| ----------- | ------------------------------------------------------------ |
| 개념        | **RFC 1058**에 정의되어 있고 대표적인 **거리 벡터(Distance Vector)** 라우팅 프로토콜 |
| 동작 원리   | - 라우터 간 거리 계산을 위한 척도로 홉수(Hop Count) 사용<br>- 16 Hop 이상이면 패킷을 폐기<br>- 180초 이내에 새로운 라우팅 정보가 수신되지 않으면 해당 경로를 이상 상태로 간주<br>- 수신된 목적지의 거리 값과 현재 거리 값을 비교하여 작은 것을 기준으로 라우팅 테이블을 변경 |
| 라우팅 정보 | 라우팅 정보 변경 시에 모든 망에 적용하므로 **큰 규모의 망에는 적합하지 않음** |



### OSPF(Open Shortest Path First)

| 구분         | 내용                                                         |
| ------------ | ------------------------------------------------------------ |
| 개념 및 특징 | - **RFC 1247** 에 정의되어 있는 IP 라우팅 프로토콜<br>- **대규모 IP망**에서 사용되며 **링크 상태(Link State)** 라우팅 프로토콜<br>- 링크에서의 전송 시간을 링크 비용으로 사용하여 각 목적지별 최단경로를 구함<br>- 네트워크에 변화가 발생했을 때 상대적으로 짧고 간단한 링크 상태 정보를 교환 |
| 동작 원리    | - Link의 delay, throughput, reliability를 이용하여 기본적인 throughput만 이용하고, Hop 수에 대한 제약이 없음.<br>- 네트워크를 Area로 구분하여 많은 라우팅 정보의 교환으로 인한 라우터의 성능저하를 예방함. 대역폭을 절약함<br>- Link 변화 감지 시 해당 Link에 대한 정보만을 즉시 모든 라우터에 전달하여 Convergence가 매우 빠름.<br>- Supernetting된 형태로 라우팅 정보를 전달할 수 있어 라우터 메모리 절약, 성능 향상 및 대역폭 절약 가능 |
| 라우터 종류  | - ABR(Area Border Router, 영역 경계 라우터): Area에 백본망을 연결해주는 라우터<br>- ASBR(Autonomous System Boundary Router, 자율 시스템 경계 라우터): 다른 AS(Autonomous System)에 속한 라우터와 경로 정보 교환<br>- IR(Internal Router, 내부 라우터): Area에 접속한 라우터<br>- BR(Backbone Router, 백본 라우터): 백본망에 접속한 모든 라우터 |

### BGP(Border Gateway Protocol)

| 구분 | 내용                                                         |
| ---- | ------------------------------------------------------------ |
| 개념 | AS 상호 간의 라우팅에 적용되는 라우팅 프로토콜로 ISP(Internet Service Provider) 사업자들 상호 간에 주로 사용되는 라우팅 프로토콜 |
| 특징 | - EGP라고 하는 Inter-domain 라우팅 프로토콜<br>- 인터넷을 AS 상호간 연결 경로로 이뤄진 방향성 그래프의 집단으로 인식: **경로 벡터 라우팅(Distance Vector Routing)** 방법을 적용하며, 경로 벡터 라우팅 테이블을 유지<br>- Looping free Routing<br>- TCP 기반 라우팅: BGP 라우팅 정보는 라우터 간에 **179** 번 포트를 통하여 TCP에 의해 신뢰성 있게 전달<br> |

