using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SalesManagement.Models
{
    public class UserDBInitializer:System.Data.Entity.DropCreateDatabaseAlways<UserDBContext>
    {
        protected override void Seed(UserDBContext context)
        {
            context.Users.Add(new User { AccountNum = "pengzeyu@qq.com" ,Password="12345678",Username="彭泽宇1"});
            base.Seed(context);
        }
    }
}