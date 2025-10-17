using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace changePhotoDate {
    class ColType : Enumeration {

        protected ColType() { }
        public ColType(int id, string name) : base(id, name) { }

        public static ColType CheckBox = new ColType(0, "√");
        public static ColType No = new ColType(1, "No");
        public static ColType FilePath = new ColType(2, "File Path");
        public static ColType DateTaken = new ColType(3, "Date Taken");
        public static ColType DateCreated = new ColType(4, "Date Created");
        public static ColType DateModified = new ColType(5, "Date Modified");
        public static ColType DateAccessed = new ColType(6, "Date Accessed");

        public static IEnumerable<ColType> List() {
            return new[] { CheckBox, No, FilePath, DateTaken, DateCreated, DateModified, DateAccessed };
        }
    };
}
