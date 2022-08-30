void print(void* ptr, char type, int size = 0)
{
    switch (type)
    {
    case 'i':
        cout << *((int*)ptr);
        break;
    case 'f':
        cout << *((float*)ptr);
        break;
    case 'd':
        cout << *((double*)ptr);
        break;
    case 'c':
        cout << *((char*)ptr);
        break;
    case 'ia':
        int* pArr = (int*)ptr;
        for (int i = 0; i < size; i++)
        {
            cout << pArr[i] << " ";
        }
        break;
    default:
        break;
    }
}
