#define DEBUG_CPP_TO_CSHARP

using System.IO;
using Google.Protobuf;
using TestMe;

namespace bug_reproduce
{
    class Program
    {
        static void Main(string[] args)
        {

#if DEBUG_CPP_TO_CSHARP
            // Check deserializatin of data sent from C++ -> C# .NET
            using (var fileStream = File.OpenRead("cpp_to_csharp_serialized_state_obj.bin"))
            {
                byte[] buf = new byte[fileStream.Length];
                fileStream.Read(buf, 0, (int)fileStream.Length);
                State_Data obj = TestMe.State_Data.Parser.ParseFrom(buf);

                var myVector = obj.MyVector;

                var comp1 = myVector[0];
                var comp2 = myVector[1];
                var comp3 = myVector[2];
                var comp4 = myVector[3];
            }

#else

            // Check serialization of data sent from C# -> C++

            State_Data newObj = new TestMe.State_Data();
            var myNewVector = newObj.MyVector;
            myNewVector.Add(1.0f);
            myNewVector.Add(1.0f);
            myNewVector.Add(1.0f);
            myNewVector.Add(1.0f);

            var newStateBuf = newObj.ToByteArray();
            using (var fileStream = File.OpenWrite("csharp_to_cpp_serialized_state_obj.bin"))
            {
                fileStream.Write(newStateBuf, 0, newStateBuf.Length);
                fileStream.Close();
            }           

#endif
                        
        }

    }

}