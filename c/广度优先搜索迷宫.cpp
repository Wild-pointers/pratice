#include <stdio.h>
struct note{
	int x;	//横坐标
	int y;	//纵坐标
	int s;	//步数 
};
int main()
{
	struct note que[2501];	//因为地图大小不超过50*50因此队列扩展不会超过2500
	int a[51][51]={0},book[51][51]={0};
	//方向数组
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//队列初始化
	head=1;
	tail=1;
	//往队列里插入迷宫入口坐标
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	flag=0;	//用来标记是否已经到达目标地点，0表示暂时还没有到，1表示到达
	//当队列不为空时循环
	while(head<tail)
	{
		//枚举四个方向
		for(k=0;k<=3;k++)
		{
			//计算下一个点的坐标
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			//判断是否是障碍物，并且已经在路上
			if(a[tx][ty]==0 && book[tx][ty]==0)
			{
				//把这个点标记为走过
				//宽搜每个点只入队一次，所以和深搜不同，不需要将book数组还原
				book[tx][ty]=1;
				//插入新的点到队列
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].s=que[head].s+1;
				tail++; 
			}
			//如果到达目标点，停止扩展，任务结束，退出循环
			if(tx==p && ty==q)
			{
				flag=1;
				break;
			} 
		}
		if(flag==1)
		break;
		head++;//当一个点扩展结束后，head++才能对后面的点再进行扩展 
	}
	//打印队列中末尾最后一个点（目标点的步数）
	//注意tail是指向队列队尾（即最后一个元素）的下一个位置，所以这里需要-1
	printf("%d",que[tail-1].s); 
} 
