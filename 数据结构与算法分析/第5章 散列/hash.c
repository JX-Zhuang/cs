int Hash(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;
    while (*Key != '\0')
    {
        HashVal = (HashVal << 5) + *Key++;
    }
    return HashVal % TableSize;
}