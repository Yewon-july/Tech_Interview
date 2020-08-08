### 네트워크 접근(Network Access) 계층

- 네트워크 계층은 **논리적인 IP 주소를 물리적 MAC 주소로 변환**하고 **에러제어**와 **흐름제어** 같은 기능을 제공한다.
- Physical Layer가 이해할 수 있는 헤더를 붙여주는 Layer, Frame 단위, Mac Address를 사용하는 계층이다.
- 통신기기 사이의 연결 및 데이터 전송 기능을 한다.
- 에러 제어, 흐름 제어 기능을 한다.
- OSI 7계층의 데이터 링크 및 물리 계층에 해당된다.



### 네트워크 접근 계층의 주요 기능

- Point-to-Point 간 신뢰성 있는 전송으로 흐름 제어(Flow Control) 기능을 담당한다.
- 에러 제어(Error Control): Error Detection(에러 검출), Error Correction(에러정정)
- MAC(Media Access Control): LAN 카드의 물리적 주소



### CSMA/CD(Carrier Sense Multiple Access/Collision Detection)

유션 LAN(Local Area Network)에서 메시지를 송수신하기 위한 접근 방법이다. CSMA/CD를 사용할 때 Collision이 발생한 경우 **Back off 알고리즘**을 이용하여 재전송한다. 리피터와 허브를 이용하면 Collision이 발생하나, Switch는 Collision을 막을 수 있다. 하지만 Switch는 브로드캐스트를 막을 수 없고, Router가 브로드캐스트를 막을 수 있다.

#### CSMA/CD 동작 과정(충돌이 발생하지 않는 경우)

1. 전송을 원하는 호스트는 네트워크에 캐리어를 감지해 전송이 가능한지 검사한다.
   - 예) 호스트 A는 호스트 D로 데이터 프레임을 전송 

1. 호스트는 전송이 가능할 경우 전송을 시작한다.
2. 호스트 A에서 발생한 프레임은 공유 매체를 통하여 호스트 B, C, D로 Broadcast된다.
3. 호스트 B, C는 목적지 IP주소가 자기가 아니라는 걸 알면 바로 프레임을 폐기한다.
4. 호스트 D는 목적지가 자기라는 것을 알고 호스트 A에게 Unicast로 응답한다.
5. 하지만 Shared Device Hup 네트워크에서는 유니캐스트와 브로드캐스트의 차이가 없다.

#### CSMA/CD 동작 과정(충돌이 발생한 경우)

1. 전송을 원하는 호스트는 네트워크에 캐리어를 감지해 전송이 가능한지 검사한다.
   - 예) 호스트 A는 호스트 D로 데이터 프레임 전송, 호스트 B는 호스트 C로 데이터 프레임 전송

1. 호스트 A에서 발생한 프레임과 호스트 B에서 발생한 프레임은 공유 매체에서 Collision을 발생시킨다.
2. Collsion이 발생되면 Jam Signal을 모든 호스트로 전송하여 Collision 발생에 대하여 알린다.
3. Jam Signal을 받은 호스트들은 일정한 시간 후에 다시 전송을 시작한다. 최대 15번까지 재전송한다.



### CSMA/CA(Carrier SEnse Multiple Access/Collision Avoidance)

- 무선 LAN(Local Area Network)에서 메시지의 송수신을 하기 위한 접근 방법이다.
- 프레임 전송 이전에 제어 메시지를 이용하여 수신자로부터 간단한 전송을 유발한다.
- 제어 신호에 대한 응답이 도착하면 프레임을 전송한다.

