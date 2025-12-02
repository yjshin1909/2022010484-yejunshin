#include <stdio.h>
#include <math.h>

#define DT 0.01                 // 시간 간격 [sec]
#define G  9.81                 // 중력 가속도 [m/s^2]
#define DEG2RAD (3.1415926535 / 180.0)   // 도(deg) -> 라디안(rad) 변환 상수

/*
  pos[0] : x좌표
  pos[1] : y좌표
  vel[0] : x방향 속도 성분
  vel[1] : y방향 속도 성분
*/

/* 초기 상태 설정 함수
   - 초기 위치 (0, 0)
   - 발사 각도, 초기 속력을 이용해 속도 성분 계산
*/
void InitState(double pos[2], double vel[2],
    double v0, double angle_deg)
{
    double angle_rad = angle_deg * DEG2RAD;  // 각도를 라디안으로 변환

    // 초기 위치
    pos[0] = 0.0;   // x = 0
    pos[1] = 0.0;   // y = 0

    // 초기 속도 성분 (vx, vy)
    vel[0] = v0 * cos(angle_rad);  // vx = v0 * cos(theta)
    vel[1] = v0 * sin(angle_rad);  // vy = v0 * sin(theta)
}

/* 상태를 한 스텝(Δt) 업데이트하는 함수
   - 입력: pos[], vel[]
   - 출력: pos[], vel[]가 직접 변경됨 (포인터/배열 사용)
   - 사용 식:
       x(t+dt) = x(t) + vx * dt
       y(t+dt) = y(t) + vy * dt
       vy(t+dt) = vy(t) - g * dt
*/
void UpdateState(double pos[2], double vel[2])
{
    // 위치 업데이트
    pos[0] = pos[0] + vel[0] * DT;   // x = x + vx * dt
    pos[1] = pos[1] + vel[1] * DT;   // y = y + vy * dt

    // 속도 업데이트 (중력은 y방향으로만 작용)
    vel[1] = vel[1] - G * DT;        // vy = vy - g * dt
}

int main(void)
{
    // 위치와 속도를 2칸짜리 배열로 선언
    double pos[2];   // pos[0] = x, pos[1] = y
    double vel[2];   // vel[0] = vx, vel[1] = vy

    double v0 = 15.0;        // 초기 속력 [m/s]
    double angle_deg = 75.0; // 발사 각도 [deg]

    double t = 0.0;          // 경과 시간 [sec]
    double maxHeight = 0.0;  // 최고 높이 [m]
    double range = 0.0;      // 수평 사거리 (최종 x 위치) [m]

    // 1) 초기 상태 설정
    InitState(pos, vel, v0, angle_deg);

    // 2) 시뮬레이션 반복
    //    y좌표(pos[1])가 0 이상인 동안 반복
    while (pos[1] >= 0.0)
    {
        // 현재 높이가 최고 높이보다 크면 갱신
        if (pos[1] > maxHeight)
        {
            maxHeight = pos[1];
        }

        // 한 스텝 진행 (위치/속도 업데이트)
        UpdateState(pos, vel);

        // 시간 증가
        t += DT;
    }

    // 로켓이 다시 지면(y=0) 아래로 떨어졌을 때의 x좌표를 수평 사거리로 간주
    range = pos[0];

    // 3) 결과 출력
    printf("=== 물로켓 시뮬레이션 결과 ===\n");
    printf("발사 각도       : %.1f [deg]\n", angle_deg);
    printf("초기 속도       : %.2f [m/s]\n", v0);
    printf("시간 간격 dt    : %.2f [s]\n", DT);
    printf("중력가속도 g    : %.2f [m/s^2]\n\n", G);

    printf("체공 시간       : %.3f [s]\n", t);
    printf("비행 중 최고 높이: %.3f [m]\n", maxHeight);
    printf("수평 사거리     : %.3f [m]\n", range);

    return 0;
}
