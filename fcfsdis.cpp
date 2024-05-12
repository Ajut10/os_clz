#include <stdio.h>
#include <math.h>
int size;
void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int cur_track, distance;
    for (int i = 0; i < size; i++)
    {
        cur_track = arr[i];
        // calculate absolute distance
        distance = fabs(head - cur_track);
        // increase the total count
        seek_count += distance;
        // accessed track is now new head
        head = cur_track;
    }
    printf("Total number of seek operations: %d\n", seek_count);
    // Seek sequence would be the same
    // as request array sequence
    printf("Seek Sequence is\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
// Driver code
int main()
{
    int disk_size;
    printf("Enter disk size:");
    scanf("%d", &disk_size);
    printf("Enter the size of input:");
    scanf("%d", &size);
    // request array
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("input[%d]:", i);
        scanf("%d", &arr[i]);
    }
    int head;
    printf("Enter intial head position:");
    scanf("%d", &head);
    FCFS(arr, head);
    return 0;
}