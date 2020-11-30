//Programmer: Dana Solitaire
namespace LABHASH
{

	template <typename RecordType, typename KeyType, std::size_t TABLE_SIZE, RecordType getflag(short), int hashkey(const KeyType&)>
	void table<RecordType, KeyType, TABLE_SIZE, getflag, hashkey>::insert(const RecordType& entry)
	{
		int index = hashkey(entry.key);
		if (data[index] != getflag(NEVER_USED))
		{
			++collision_count;
			++index;
		}
		data[index] = entry;
		//entry.definition;
	}

} // End of LABHASH namespace
