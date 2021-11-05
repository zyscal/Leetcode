// 多生产多消费模型
semaphore DoConsume = 0; //是否正在消费
semaphore Doproduct = 0; // 是否正在生产
semaphore mutex = 1; // 是否可以访问缓冲区
semaphore full = 0; // 是否满
semaphore empty = n; // 是否空

produce(){
    while (true)
    {
        create a Resource;
        P(Doproduct);
        P(empty);
        P(mutex);
        queue.push();
        V(mutex);
        V(full);
        V(Doproduct);
    }
}

consumer(){
    while (true)
    {
        P(DoConsume);
        P(full);
        P(mutex);
        queue.top();
        queue.pop();
        V(mutex);
        V(empty);
        V(Doconsume);
    }
}
void main(){
    int ConsumerNum = n; // 消费者数量
    int Producer = m; // 生产者数量
    for(int i = 0 ; i < n; i++){
        consumer();
    }
    for(int i = 0 ; i < m; i++){
        producer();
    }
}