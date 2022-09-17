using System.IO;
using Google.Protobuf;
using TestMe;

namespace bug_reproduce
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var fileStream = File.OpenRead("serialized_state_obj.bin"))
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

            // Code in here !
        }

    }

}