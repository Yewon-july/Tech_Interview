## Synchronous vs Asynchronous

### 동기 프로그래밍

- Synchronous Programming, Blocking Programming
- 하나의 요청이 처리되는 동안 다른 요청이 처리되지 못하며 요청이 완료되어야만 다음 처리가 가능한 방식
- 



### 비동기 프로그래밍

- Asynchronous Programming, Non-blocking Programming
- 하나의 요청에 따른 응답을 즉시 처리하지 안하도, 그 대기 시간 동안 또 다른 요청에 대해 처리 가능한 방식
- Nodejs
  - 비동기 IO를 지원하며, Single Thread 기반으로 동작하는 서버
  - 클라이언트의 요청을 비동기로 처리하기 위해, event가 발생하며, event loop가 처리
  - event loop가 처리하는 동안, 제어는 다음 요청으로 넘어가며, 처리가 완료되면 callback을 호출하여 처리 완료를 호출 측에 알려줌.
  - 복잡한 처리 방식에서 콜백을 사용하면 콜백 헬 발생.
  - 비동기작업을 콜백에 비해 쉽게 컨트롤하기 위해 Promise 사용.
  - Async/await는 promise보다 더욱 절차적(동기적)인 방법으로 프로그래밍 가능
- CPU를 많이 사용하는 처리 작업이나, 대용량 파일에서는 옳지 못함.



참고: https://jinn-blog.tistory.com/87