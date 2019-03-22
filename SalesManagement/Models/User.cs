using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SalesManagement.Models
{
    public class User
    {
        public virtual int UserId { get; set; }
        public virtual string AccountNum { get; set; }
        public virtual string Password { get; set; }
        public virtual string Username { get; set; }
    }
}